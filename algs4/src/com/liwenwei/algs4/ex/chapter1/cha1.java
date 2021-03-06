package com.liwenwei.algs4.ex.chapter1;

public class cha1 {

	// 1.1.9
	private static String toBinaryString(int N) {
		String s = "";
		for (int i = N; i > 0; i /= 2) {
			s = (i % 2) + s;
		}
		return s;
	}

	// 1.1.11
	// 二维布尔数组的内容。 其中， 使用 * 表示真， 空格表示假。 打印出行号和列号
	private static void printBooleanArray(boolean[][] arr) {
		System.out.print(" ");
		for (int i = 0; i < arr[0].length; i++) {
			System.out.print((i + 1) + " "); // column line
		}
		System.out.println();

		for (int i = 0; i < arr.length; i++) {
			System.out.print(i + 1); // row line
			for (int j = 0; j < arr[i].length; j++) {
				if (arr[i][j]) {
					System.out.print("*");
				} else {
					System.out.print(" ");
				}
			}
			System.out.println();
		}
	}

	// 1.1.13
	// transpose matrices(转置矩阵)
	private static int[][] transpose(int[][] arr) {
		int row = arr[0].length;
		int column = arr.length;
		int[][] arr_transpose = new int[row][column];
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				arr_transpose[i][j] = arr[j][i];
			}
		}
		return arr_transpose;
	}
	
	// 1.1.14
	// 接受一个整型参数 N， 返回不大于 log2N 的最大整数
	// x <= log2N => 2^x <= N => return x
	private static int lg(int N) {
		int max = 1;
		int x = 0;
		while (max <= N) {
			max *= 2;
			if(max <= N) {
				x++;
			}
		}
		return x;
	}
	
	// 1.1.14
	// 每次除2
	private static int lg1(int N) {
		int x = 1;
		for (int n = N; n > 1; n /= 2) {
			x++;
		}
		return x;
	}

	public static void main(String[] args) {
		System.out.println(toBinaryString(4));

		boolean[][] boolarr = { { true, false }, { false, true } };
		printBooleanArray(boolarr);
		
		int[][] transposeArr = {{1,2}, {3, 4}, {5, 6}};
		transpose(transposeArr);
		
		System.out.println(lg(2049));
		System.out.println(lg1(2049));

	}

}