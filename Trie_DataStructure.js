// * A trie or a prefix tree is a particular kind of search tree, where nodes are usually keyed by strings. Tries can be used to implement data structures like sets and associative arrays, but they really shine when we need to perform an ordered traversal or to efficiently search for keys starting with a specific prefix

// * used in autocomplete and spellchecker

class TrieNode {
	constructor() {
		this.children = {};
		this.isEndOfWord = false;
	}
}

class Trie {
	constructor() {
		this.root = new TrieNode();
	}

	// Insert a word into the Trie
	insert(word) {
		let node = this.root;
		for (const char of word) {
			if (!node.children[char]) {
				node.children[char] = new TrieNode();
			}
			node = node.children[char];
		}
		node.isEndOfWord = true;
	}

	// Search for a word in the Trie
	search(word) {
		let node = this.root;
		for (const char of word) {
			if (!node.children[char]) {
				return false;
			}
			node = node.children[char];
		}
		return node.isEndOfWord;
	}

	// Check if any words in the Trie start with the given prefix
	startsWith(prefix) {
		let node = this.root;
		for (const char of prefix) {
			if (!node.children[char]) {
				return false;
			}
			node = node.children[char];
		}
		return true;
	}
}

// Example usage:
const trie = new Trie();
trie.insert("apple");
console.log(trie.search("apple")); // true
console.log(trie.search("app")); // false
console.log(trie.startsWith("app")); // true
trie.insert("app");
console.log(trie.search("app")); // true
