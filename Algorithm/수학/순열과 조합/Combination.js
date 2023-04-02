// -- Methods ====================

const comb = function (arr, selectNumber) {
  const results = [];

  // n개중에서 1개 선택할 때(nC1), 바로 모든 배열의 원소 return
  if (selectNumber === 1) return arr.map((el) => [el]);

  arr.forEach((fixed, index, origin) => {
    // 해당하는 fixed를 제외한 나머지 뒷 부분
    const rest = origin.slice(index + 1);

    // 나머지에 대해서 조합을 구한다.
    const combArr = comb(rest, selectNumber - 1);

    //  돌아온 조합에 떼 놓은(fixed) 값 붙이기
    const attached = combArr.map((el) => [fixed, ...el]);

    // 배열 spread syntax 로 모두다 push
    results.push(...attached);
  });

  // 결과 담긴 results return
  return results;
};

// -- Output ====================

let arr = [1, 2, 3];
console.log(comb(arr, 2));
