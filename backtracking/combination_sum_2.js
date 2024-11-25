// $ DOES NOT WORK!!

/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.
*/

// const candidates = [10, 1, 2, 7, 6, 1, 5];
// const target = 8;

//! this throws time limit exceeded.

const candidates = [
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
];

console.log(candidates.length);

const target = 30;

candidates.sort((a, b) => a - b);

const res = new Set();

const backtrack = (sum = 0, currCombination = [], start = 0) => {
	if (sum > target) return;

	if (sum === target) {
		res.add(JSON.stringify([...currCombination]));
		return;
	}

	for (let i = start; i < candidates.length; i++) {
		currCombination.push(candidates[i]);
		backtrack(sum + candidates[i], currCombination, i + 1);
		currCombination.pop();
	}
};

backtrack();

const resArray = Array.from(res).map((str) => JSON.parse(str));

console.log(resArray);
