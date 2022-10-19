//leetcode ID:12.                                         Problem name : Integer to Roman
//level : Medium

var intToRoman = function(num) {
    const unitsArr = [['I', 'V'], ['X', 'L'], ['C', 'D'], ['M']];
    let result = '';
    while(num > 0) {
      const index = Math.floor(Math.log10(num));
      const units = unitsArr[index];
      const currentNum = Math.floor(num / Math.pow(10, index));
      if (currentNum < 4) {
        for(i = 1; i <= currentNum; i++) {
          result = result + units[0];
        }
      } else if (currentNum === 4) {
        result = result + units[0] + units[1];
      } else if (currentNum === 5) {
        result = result + units[1];
      } else if (currentNum < 9) {
        result = result + units[1];
        for(i = 1; i <= currentNum - 5; i++) {
          result = result + units[0];
        }
      } else {
        const upUnits = unitsArr[index + 1];
        result = result + units[0] + upUnits[0];
      }
      if (index === 0) {
        break;
      }
      num = num % Math.pow(10, index);
    }
    return result;
};
