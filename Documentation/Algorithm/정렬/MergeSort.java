package 정렬;

import java.util.Arrays;

public class MergeSort {
	
	private static int[] sortedArr;
	
	public static void main(String[] args) {
		int[] arr = new int[] { 78, 99, 21, 22, 3, 2, 4, 60 };
		sortedArr = new int[arr.length];
		
		System.out.println("소팅 전 : " + Arrays.toString(arr));
		// 소팅
		mergeSort(arr, 0, arr.length - 1);
		System.out.println("소팅 후 : " + Arrays.toString(arr));
	}

	private static void mergeSort(int[] arr, int left, int right) {
		if(left < right) {
			int mid = left + (right - left) / 2;
			mergeSort(arr, left, mid);
			mergeSort(arr, mid + 1, right);
			merge(arr, left, mid, right);
		}
	}

	private static void merge(int[] arr, int left, int mid, int right) {
		int L = left;
		int R = mid + 1;
		int index = left;
		
		while((L <= mid) && (R <= right)) {
			if(arr[L] <= arr[R]) sortedArr[index++] = arr[L++];
			else sortedArr[index++] = arr[R++];
		}
		
		if(L <= mid) {
			for(int i = L; i <= mid; i++) {
				sortedArr[index++] = arr[i];
			}
		}
		else {
			for(int i = R; i <= right; i++) {
				sortedArr[index++] = arr[i];
			}
		}
		
		for(int i = left; i <= right; i++) {
			arr[i] = sortedArr[i];
		}
	}
	
}
