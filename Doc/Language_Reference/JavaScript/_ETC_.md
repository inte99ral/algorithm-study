# \_ETC\_

## AJAX

- cosnt 객체 값은 변화하지 않았다고 봤기 때문에 내부가 변하더라도 map 에서 같은 키취급을 한다 잊지말것

```javascript
interface responseType {
  id: number;
  startTime: Date;
  endTime: Date;
  issueSummary: string;
  version: number;
  issueCode: string;
  progress: number;
  userId: number;
  parentId: number;
}

const startYear = 1999;
const endYear = 2023;
const calenderData = new Map<string, number>();

// Return
return new Promise<Map<string, number>>((resolve, reject) => {
  widgetDataAxios
    .get(
      `/project-service/gantt?start=${startYear}-01-01T00%3A00%3A00&end=${endYear}-01-01T00%3A00%3A00&op=1&projectId=${projectId}`,
    )
    .then(response => {
      response.data.map((item: responseType) => {
        const tempDate = new Date(item.startTime);
        const endDate = new Date(item.endTime);

        while (tempDate < endDate) {
          const tempKey = tempDate.getFullYear() + '-' + tempDate.getMonth();
          calenderData.set(tempKey, (calenderData.get(tempKey) || 0) + 1);
          tempDate.setDate(tempDate.getDate() + 1);
        }
      });

      console.log('[달력데이터 값]', calenderData);

      // const testDate = new Date(2022, 12, 30);
      // testDate.setDate(testDate.getDate() + 1);
      // console.log('[달력데이터 값]', testDate);
      resolve(calenderData);
    })
    .catch(error => {
      reject(error);
    });
```
