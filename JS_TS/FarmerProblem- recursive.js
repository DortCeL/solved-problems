//! Question: A farmer wants the biggest square of 1s possible for farming. help him.
//* Recursive solution

const matrix = [
	[0, 1, 1, 0, 1],
	[1, 1, 0, 1, 0],
	[0, 1, 1, 1, 0],
	[0, 1, 1, 1, 0],
	[1, 1, 1, 1, 1],
	[0, 0, 0, 0, 0],
];

const isSquareOfOnes = (row, col, size) => {
	//* this function checks if there exists a square of 1s of size "SIZE" at the position (ROW, COL) or not; it checks frop top left to bottom right;

	if (row + size >= matrix.length || col + size >= matrix[0].length)
		return false;

	for (let i = row; i < row + size; i++) {
		for (let j = col; j < col + size; j++) {
			if (matrix[i][j] == 0) return false;
		}
	}
	return true;
};

let maxSize = 0;

for (let i = 0; i < matrix.length; i++) {
	for (let j = 0; j < matrix[0].length; j++) {
		if (matrix[i][j] == 1) {
			let size = 1;
			while (isSquareOfOnes(i, j, size)) {
				maxSize = Math.max(maxSize, size);
				size++;
			}
		}
	}
}

console.log(maxSize);
