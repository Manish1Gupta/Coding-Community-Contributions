//leetcode ID : 218                                          Problem name :  The Skyline Problem
//level : hard

/**
 * @param {number[][]} buildings
 * @return {number[][]}
 */
var getSkyline = function(buildings) {
        if (buildings.length === 0) return [];

    let startEndHeightList = [];
    for (let building of buildings){
        let [start, end, height] = building;
        startEndHeightList.push([start, 0-height]);
        startEndHeightList.push([end, height]);
    }
    startEndHeightList.sort((a,b)=> a[0]===b[0] ? a[1]-b[1] : a[0]-b[0]) // ascending sort by x, y
    let result = [];
    let currHeights = [0]; // init with ground height 0
    let prevMaxHeight = 0;
    for (let i = 0; i < startEndHeightList.length; i++){
        let [pos, height] = startEndHeightList[i];
        if (height < 0){ // new building, add to currHeights
            currHeights.push(0-height);
        }else{ // end of building, add to map as 0
            let removeIdx = currHeights.indexOf(height);
            currHeights.splice(removeIdx,1);
        }

        let currMaxHeight = Math.max(...currHeights)
        if (currMaxHeight != prevMaxHeight) result.push([pos, currMaxHeight])
        prevMaxHeight = currMaxHeight;
    }
    return result;
};
