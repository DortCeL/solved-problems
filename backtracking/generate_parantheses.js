const n = 3;

const res = [];

const generateParentheses = (
	currString = "",
	numOpening = n,
	numClosing = n
) => {
	if (numClosing === 0 && numOpening === 0) {
		res.push(currString);
		return;
	}

	if (numOpening > 0 && numOpening <= numClosing) {
		generateParentheses(currString + "(", numOpening - 1, numClosing);
	}
	if (numClosing > 0 && numOpening <= numClosing)
		generateParentheses(currString + ")", numOpening, numClosing - 1);
};

generateParentheses();

console.log(res);
