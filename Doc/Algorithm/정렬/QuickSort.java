package 정렬;

import java.util.Arrays;

public class QuickSort {
	public static void main(String[] args) {
		int[] arr = { 3, 2, 4, 6, 9, 1, 8, 7, 5 };
		System.out.println(Arrays.toString(arr));
		quickSort(arr, 0, arr.length - 1);
		System.out.println(Arrays.toString(arr));
	}

	
	private static void quickSort(int[] arr, int left, int right) {
		if(left < right) {
			int pivot = partition1(arr, left, right);
			quickSort(arr, left, pivot - 1);
			quickSort(arr, pivot + 1, right);
		}
	}
	
	// Hoare-Partition 처음 값을 기준으로 L과 R이 양쪽 끝에서 가운데로 만난다.
	private static int partition1(int[] arr, int left, int right) {
		int pivot = arr[left];
		int L = left + 1;
		int R = right;
		int tmp;
		
		while(L <= R) {
			// L : pivot 보다 큰 값을 찾을 때까지 이동하겠다.
			// 범위 제한을 하지 않을 경우 인덱스 에러가 난다.
			while(L <= R && arr[L] <= pivot) L++;
			
			// R : privot 보다 작은 값을 찾을 때까지 이동하겠다.
			while(arr[R] > pivot) R--;
			
			// 교차가 안됬다면
			if(L < R) {
				tmp = arr[L];
				arr[L] = arr[R];
				arr[R] = tmp;
			}
		}
		// pivot 의 위치를 양쪽 파티션의 가운데로
		tmp = arr[left];
		arr[left] = arr[R];
		arr[R] = tmp;
		
		return R;
	}
	
	// Lomuto-Partition 끝 값을 기준으로 0번 부터 L 과 R 이 같이 이동한다.
		private static int partition2(int[] arr, int left, int right) {
			int pivot = arr[right];
			int L = left + 1;
			int R = right;
			int tmp;
			
			while(L <= R) {
				// L : pivot 보다 큰 값을 찾을 때까지 이동하겠다.
				// 범위 제한을 하지 않을 경우 인덱스 에러가 난다.
				while(L <= R && arr[L] <= pivot) L++;
				
				// R : privot 보다 작은 값을 찾을 때까지 이동하겠다.
				while(arr[R] > pivot) R--;
				
				// 교차가 안됬다면
				if(L < R) {
					tmp = arr[L];
					arr[L] = arr[R];
					arr[R] = tmp;
				}
			}
			// pivot 의 위치를 양쪽 파티션의 가운데로
			tmp = arr[left];
			arr[left] = arr[R];
			arr[R] = tmp;
			
			return R;
		}
	
	
	
	
}
