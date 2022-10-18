//leetcode ID : 168                                             Problem Name :  Excel Sheet Column Title
//level : Easy

var convertToTitle = function(columnNumber) {
     let excelColumn = '';
    let charCode;

    while (columnNumber > 0) {
        charCode = (columnNumber - 1) % 26;
        excelColumn = String.fromCharCode(65 + charCode) + excelColumn;
        columnNumber = parseInt((columnNumber - charCode) / 26);
    }
    return excelColumn;
};
