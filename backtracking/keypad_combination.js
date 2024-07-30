const keypad = {
	2: "abc",
	3: "def",
	4: "ghi",
	5: "jkl",
	6: "mno",
	7: "pqrs",
	8: "tuv",
	9: "wxyz",
};

const result = [];

const digits = "23";

const backtrack = (currentString = "", index = 0) => {
	// base case
	if (currentString.length === digits.length) {
		result.push(currentString);
		return;
	}

	// recursion
	for (let char of keypad[digits[index]]) {
		backtrack(currentString + char, index + 1);
	}
	// backtrack
};

backtrack();

console.log(result);
