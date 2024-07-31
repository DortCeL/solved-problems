/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.
*/

const candidates = [10, 1, 2, 7, 6, 1, 5];
const target = 8;

candidates.sort((a, b) => a - b);

const res = [];

const backtrack = (sum = 0, currCombination = [], start = 0) => {
	if (sum > target) return;

	if (sum === target) {
		res.push([...currCombination]);
		return;
	}

	for (let i = start; i < candidates.length; i++) {
		currCombination.push(candidates[i]);
		backtrack(sum + candidates[i], currCombination, i + 1);
		currCombination.pop();
	}

	//! I tried this at first, but it returns all the combinations, not skipping duplicate combinations

	// for (let x of candidates) {
	// 	backtrack(sum + x, currCombination);
	// 	currCombination.pop();
	// }
};

backtrack();

console.log(res);
