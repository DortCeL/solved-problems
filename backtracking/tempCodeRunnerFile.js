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
};

backtrack();

console.log(res);