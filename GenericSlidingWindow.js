//! Fixed size window
function slidingWindowProblem(arr, k) {
	// 1. Initialize variables
	let windowStart = 0;
	let currentResult = 0; // Could be sum, count, etc.
	let bestResult = -Infinity; // Adjust based on problem: -Infinity for max, 0 for sum, etc.

	// 2. Expand the window
	for (let windowEnd = 0; windowEnd < arr.length; windowEnd++) {
		// Add the current element to the window's result
		currentResult += arr[windowEnd];

		// 3. Shrink the window if necessary
		if (windowEnd >= k - 1) {
			// When the window size matches the requirement
			// Update the best result
			bestResult = Math.max(bestResult, currentResult); // Depends on the problem

			// Remove the element going out of the window
			currentResult -= arr[windowStart];

			// Slide the window forward
			windowStart++;
		}
	}

	return bestResult;
}

//! Dynamic sized window
function dynamicSlidingWindowProblem(arr, condition) {
	// 1. Initialize variables
	let windowStart = 0;
	let currentResult = 0; // Can be sum, count, etc.
	let bestResult = Infinity; // Adjust based on the problem: Infinity for min, -Infinity for max, etc.

	// 2. Expand the window
	for (let windowEnd = 0; windowEnd < arr.length; windowEnd++) {
		// Add the current element to the window's result
		currentResult += arr[windowEnd];

		// 3. Shrink the window dynamically
		while (condition(currentResult)) {
			// Condition based on problem requirements
			// Update the best result
			bestResult = Math.min(bestResult, windowEnd - windowStart + 1); // Depends on the problem

			// Remove the element going out of the window
			currentResult -= arr[windowStart];

			// Slide the window forward
			windowStart++;
		}
	}

	// Return the best result (or handle edge cases)
	return bestResult === Infinity ? -1 : bestResult; // Adjust return value for specific problems
}
