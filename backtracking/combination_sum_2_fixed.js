/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.
*/

// * watch COMBINATION_SUM_2 by takeuforward...

const candidates = [10, 1, 2, 7, 6, 1, 5];
const target = 8;

// const candidates = [
// 	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
// 	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
// 	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
// 	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
// ];

// const target = 30;

candidates.sort((a, b) => a - b);

const res = [];

const backtrack = (sum = 0, currCombination = [], start = 0) => {
	if (sum === target) {
		res.push([...currCombination]);
		return;
	}

	for (let i = start; i < candidates.length; i++) {
		if (candidates[i] > target - sum) break;
		if (i > start && candidates[i] === candidates[i - 1]) continue;

		currCombination.push(candidates[i]);
		backtrack(sum + candidates[i], currCombination, i + 1);
		currCombination.pop();
	}
};

backtrack();
console.log(res);
