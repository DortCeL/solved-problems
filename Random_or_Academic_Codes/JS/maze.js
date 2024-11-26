const adj = new Map();
const level = new Map();

adj.set(0, [1, 3]);
adj.set(1, [0, 2]);
adj.set(2, [1, 5]);
adj.set(3, [0, 4, 6]);
adj.set(4, [3, 7, 5]);
adj.set(5, [4]);
adj.set(6, [3]);
adj.set(7, [4, 8]);
adj.set(8, [7]);

// $ Functions

function shortest_path(src, target, visited = new Set(), parent = new Map()) {
  let path_exists = false;

  const q = [src];

  level.set(src, 0);
  visited.add(src);

  while (q.length > 0) {
    let item = q.shift();
    if (item === target) path_exists = true;

    for (neighbor of adj.get(item)) {
      if (!visited.has(neighbor)) {
        level.set(neighbor, level.get(item) + 1); // set level

        parent.set(neighbor, item); // set parent

        q.push(neighbor);
        visited.add(neighbor);
      }
    }
  }

  // find shortest path :
  if (path_exists) {
    const path = [];

    let curr = target;
    while (curr !== src) {
      path.push(curr);
      curr = parent.get(curr);
    }
    path.push(curr);
    path.reverse();
    console.log("Shortest Path : ", path);
  }
}

// * IT WORKS (partially) !!!!

// function findAllPaths(src, target, visited = new Set(), path = []) {
//   visited.add(src);
//   path.push(src);
//   if (src === target) {
//     console.log(path);
//   } else {
//     for (let n of adj.get(src)) {
//       if (!visited.has(n)) {
//         visited.add(n);
//         findAllPaths(n, target, visited, path);
//       }
//     }
//   }

//   // backtracking ( idk how it works )
//   path.pop();
//   visited.delete(src);
// }

function findAllPaths(src, target) {
  const visited = new Set();
  const path = [];
  const paths = [];

  //$ -------------DFS start
  function dfs(node) {
    visited.add(node);
    path.push(node);

    if (node === target) {
      paths.push([...path]);
    }

    const neighbors = adj.get(node);
    if (neighbors && neighbors.length > 0) {
      for (let n of neighbors) {
        if (!visited.has(n)) {
          dfs(n);
        }
      }
    }
    visited.delete(node);
    path.pop();
  }
  //$ --------------DFS end

  dfs(src);

  for (let i = 0; i < paths.length; i++) {
    console.log("Path", i + 1, ": ", paths[i]);
  }
}

shortest_path(1, 6);
findAllPaths(1, 6);

// $ Maze representation

//   ___________
//  | 0   1   2 |
//  |   _____   |
//  | 3   4   5 |
//  |        ____
//  | 6 | 7   8 |
//  | ___________
