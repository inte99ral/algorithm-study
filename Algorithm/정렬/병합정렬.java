package 정렬;

import java.util.Arrays;

public class 병합정렬 {
	private static int[] arr = {2, 9, 6, 1, 7, 5, 3, 8, 4};
	
	public static void main(String[] args) {
		mergeSort(arr);
		System.out.println(Arrays.toString(arr));
	}
	
	private static void mergeSort(int[] arr) {
		// 초동
		mergeSortRecur(arr, 0, arr.length - 1);
		return;
	}
	
	private static void mergeSortRecur(int[] arr, int left, int right) {
		if(left >= right) return;
		
		// 절반 위치를 찾고
		int mid = left + (right - left) / 2;
		
		// 계속 반으로 가르면서 확인한다
		mergeSortRecur(arr, left, mid);
		mergeSortRecur(arr, mid + 1, right);
		
		// 반으로 가르고 합친다
		merge(arr, left, mid, right);
		return;
	}
	
	private static void merge(int[] arr, int left, int mid, int right) {
		int index = left;
		int L = left;
		int R = mid + 1;
		
		int[] temp = new int[arr.length];
		
		while(L <= mid && R <= right) {
			if(arr[L] > arr[R]) temp[index++] = arr[R++];
			else temp[index++] = arr[L++];
		}
		
		if(L <= mid) for(int l = L; l <= mid; l++) temp[index++] = arr[l];
		else for(int r = R; r <= right; r++) temp[index++] = arr[r];
		
		for(int i = left; i <= right; i++) {
			arr[i] = temp[i];
		}
		
		return;
	}
	
//	private static void swap(int[] arr, int i, int j) {
//		int temp = arr[i];
//		arr[i] = arr[j];
//		arr[j] = temp;
//		return;
//	}
}
