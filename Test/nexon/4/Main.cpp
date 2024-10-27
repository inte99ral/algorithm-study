int minDeletions(vector<int> arr) {
    int answer = 0;
    int size = arr.size();
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] < arr[i + 1]) continue;
        
        int leftSt = i;
        int leftEd = i;
        int leftLen = 0;
        
        int rightSt = i + 1;
        int rightEd = i + 1;
        int rightLen = 0;
        
        while (rightEd < size - 1) {
            if (arr[leftEd] < arr[rightEd + 1]) break;
            if (arr[rightEd] > arr[rightEd + 1]) break;
            rightEd++;
        }
        
        while (leftSt > 1) {
            if (arr[leftSt - 1] == -1) leftLen--;
            else if (arr[leftSt - 1] < arr[rightSt]) break;
            leftSt--;
        }
        
        rightLen += rightEd - rightSt + 1; 
        leftLen += leftEd - leftSt + 1; 
        
        if (leftLen < rightLen) {
            for (int j = rightSt; j <= rightEd; j++) {
                arr[j] = -1;
            }
            answer += rightLen;
        }
        else {
            for (int j = leftSt; j <= leftEd; j++) {
                arr[j] = -1;
            }
            answer += leftLen;
        }
        
        cout << leftLen << " : " << rightLen << "\n";
        
        i += rightLen - 1;
    }
    
    return answer;
}