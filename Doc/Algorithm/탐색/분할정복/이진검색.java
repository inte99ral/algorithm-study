package 분할정복;

public class 이진검색 {
	public static void main(String[] args) {
		int[] arr = { 1, 7, 9, 13, 19, 28, 31, 39, 41 }; 
	}
	
	static boolean binarySearch(int[] arr, int key) {
		int left = 0;
		int right = arr.length - 1;
		
		while(left <= right) {
			// int mid = (left + right) / 2; 오버플로우 방지 안함
			int mid = left - (right - left) / 2;
			
			if(arr[mid] == key)
				return true;
			else if(arr[mid] > key)
				right = mid - 1;
			else
				left = mid + 1;
		}
		
		return false;
	}
}
