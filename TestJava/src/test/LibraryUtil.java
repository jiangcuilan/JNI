package test;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedHashSet;
import java.util.Set;
import java.util.Vector;


/**
 * JCTPLibrary工具类
 * 
 * @author Hraink E-mail:Hraink@Gmail.com
 * @version 2013-1-28 下午9:24:01
 */
@SuppressWarnings("unchecked")
public class LibraryUtil {

	private static boolean inited;
	

	private static final String LIB_PATH = "lib/";
	private static final String[] LIBS = {  "TestC.dll", "TestJni.dll" };

	private static File extractedLibrariesTempDir;

	private static final int maxTempFileAttempts = 20;

	static {
		try {
			extractedLibrariesTempDir = createTempDir("CTPExtractedLibraries");
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

	public static synchronized void initLibrary() {
		if (inited) {
			return;
		}
		inited = true;

		for (String ctpLib : LIBS) {
			boolean loaded = false;
			if (!loaded) {
				String ctpLibFilePath = LIB_PATH + ctpLib;
				try {
					File libFile = extractEmbeddedLibraryResource(ctpLibFilePath);
					if (libFile == null) {
						throw new FileNotFoundException("Failed to extract embedded library '" + ctpLibFilePath + ")");
					}
					System.load(libFile.toString());
					loaded = true;
				} catch (IOException ex) {
					ex.printStackTrace();
				}
				if (!loaded) {
					System.loadLibrary(LIB_PATH + ctpLib);
				}
			}
		}
	}

	public static synchronized void release() {

		for (String ctpLibName : LIBS) {
			unloadNativeLibs(ctpLibName);
		}

		for (File libraryFile : temporaryExtractedLibraryCanonicalFiles) {
			libraryFile.delete();
		}
	}

	private static File extractEmbeddedLibraryResource(String path) throws IOException {
		int len;
		byte[] b = new byte[8196];
		File file = new File(path);
		InputStream in = new FileInputStream(file);

		String fileName = new File(path).getName();
		File libFile = new File(extractedLibrariesTempDir, fileName);
		OutputStream out = new BufferedOutputStream(new FileOutputStream(libFile));
		while ((len = in.read(b)) > 0)
			out.write(b, 0, len);
		out.close();
		in.close();

		addTemporaryExtractedLibraryFileToDeleteOnExit(libFile);
		addTemporaryExtractedLibraryFileToDeleteOnExit(libFile.getParentFile());

		return libFile;
	}

	private static File createTempDir(String prefix) throws IOException {
		File dir;
		for (int i = 0; i < maxTempFileAttempts; i++) {
			dir = File.createTempFile(prefix, "");
			if (dir.delete() && dir.mkdirs()) {
				return dir;
			}
		}
		throw new RuntimeException(
				"Failed to create temp dir with prefix '" + prefix + "' despite " + maxTempFileAttempts + " attempts!");
	}

	private static Set<File> temporaryExtractedLibraryCanonicalFiles = Collections
			.synchronizedSet(new LinkedHashSet<File>());

	private static void addTemporaryExtractedLibraryFileToDeleteOnExit(File file) throws IOException {
		File canonicalFile = file.getCanonicalFile();

		temporaryExtractedLibraryCanonicalFiles.add(canonicalFile);

		canonicalFile.deleteOnExit();
	}

	public static boolean isInited() {
		return inited;
	}

	
	private static void unloadNativeLibs(String dllName) {
		try {
			ClassLoader classLoader = LibraryUtil.class.getClassLoader();
			Field field = ClassLoader.class.getDeclaredField("nativeLibraries");
			field.setAccessible(true);
			Vector<Object> libs = (Vector<Object>) field.get(classLoader);
			Iterator<Object> it = libs.iterator();
			Object o;

			while (it.hasNext()) {
				o = it.next();

				Field[] fs = o.getClass().getDeclaredFields();

				boolean hasInit = false;
				for (int k = 0; k < fs.length; k++) {
					if (fs[k].getName().equals("name")) {
						fs[k].setAccessible(true);
						String dllPath = fs[k].get(o).toString();
						if (dllPath.endsWith(dllName)) {
							hasInit = true;
						}
					}
				}

				if (hasInit) {
					Method finalize = o.getClass().getDeclaredMethod("finalize", new Class[0]);
					finalize.setAccessible(true);
					finalize.invoke(o, new Object[0]);
				}
			}
		} catch (Exception ex) {
			throw new RuntimeException(ex);
		}
	}
}
