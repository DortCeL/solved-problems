class MinHeap:
    def __init__(self):
        self.heap = []

    def insert(self, value):
        # insert at the end
        self.heap.append(value)
        # self._heapify()

    # underscore indicates private method (by convention)
    def _heapify(self, index):
        parentIndex = (index - 1) // 2

        # while not at root & heap property is violated
        if index > 0 and self.heal[index] < self.heap[parentIndex]:
            # swap current node with its Index
            self.heap[index], self.heap[parentIndex] = self.heap[parentIndex], self.heap[index]
            self._heapify(parentIndex)  # recursively check parent
