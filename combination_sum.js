/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/

const candidates = [2, 3, 6, 7];
const target = 7;

const res = [];

const backtrack = (sum = 0, currCombination = [], start = 0) => {
	if (sum > target) return;

	if (sum === target) {
		res.push([...currCombination]);
		return;
	}

	for (let i = start; i < candidates.length; i++) {
		currCombination.push(candidates[i]);
		backtrack(sum + candidates[i], currCombination, i);
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
