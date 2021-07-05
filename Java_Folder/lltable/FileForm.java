package lltable;

import java.io.*;
import java.util.ArrayList;

public class FileForm {
	public String testString = "";

	public FileForm(String testString) {
		this.testString = testString;
	}

	ArrayList<String[]> processList = new ArrayList<String[]>();
	public static void main(String[] args) {

		BasicData data = new BasicData();
		String[][] table = data.getTable();
		File tableFile = new File("/Users/sfky/Desktop/Table.csv");
		try {
			OutputStreamWriter tableStream = new OutputStreamWriter(new FileOutputStream(tableFile));
			BufferedWriter tableText = new BufferedWriter(tableStream);

			tableText.write("Symbols");
			for (int i = 0; i < data.getVt().length; i++) {
				tableText.write("," + data.getVt()[i]);
			}
			for (int i = 0; i < data.getVn().length; i++) {
				tableText.newLine();
				tableText.write(data.getVn()[i]);
				for (int j = 0; j < data.getVt().length; j++) {
					tableText.write("," + table[i][j]);
				}
			}
			tableText.flush();
			tableText.close();
		} catch (FileNotFoundException exceptionFile) {
			exceptionFile.printStackTrace();
		} catch (IOException exceptionIO) {
			exceptionIO.printStackTrace();
		}
	}
}
