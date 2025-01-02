/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */

var findMaxAverage = function (nums, k) {
	let left = 0;

	let avg = -Infinity;
	let sum = 0;

	for (let right = 0; right < nums.length; right++) {
		// add to sum
		sum += nums[right];

		// window size hit
		if (right - left + 1 == k) {
			avg = Math.max(avg, sum / k);

			sum -= nums[left];
			left++;
		}
	}

	return avg;
};

let nums = [1, 12, -5, -6, 50, 3];
let k = 4;
console.log(findMaxAverage(nums, k));
