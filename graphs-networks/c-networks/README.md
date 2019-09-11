# C-Networks

Two programs built with C that demonstrate the functionality of both an adjacency matrix and an adjacency list. Who needs a big bulky NetworkX Python program when you can accomplish the same task with an elegant adjacency list or matrix? This suite of programs serves to demonstrate graph theory programming fundamentals both as a learning exercise and as a set of boilerplate that can be used to build graph relationships.

The two programs currently in the `c-networks` project are:
 * list-network
 * matrix-network

The two programs accomplish similar goals, but were created with different goals in mind because of the nature of their formations.

The `list-network` program assigns a link between two random nodes for at most ( N * (N-1) ) / 2 nodes in the graph since that is the maximum number of links in a complete graph. This means that the `list-network` program can have links making some inter-node connections stronger than others.

The `matrix-network` program goes through each node pair for all N nodes, generates a normally distributed random floating value, and then makes a link if that value is over a user-specified threshold value. This method was inspired by work done by Paul Erdos and Alfred Renyi in 1959 at the genesis of graph theory. This sort of random network lends itself to many insights regarding the formation of networks within natural phenomena.

Both of the programs are quite fun to fiddle with and can create some insightful figures for learning the principles of graph theory.

## Getting Started

The beautiful thing about creating networks/graphs in C is that they port to most any system quite easily.

### Prerequisites
The only external commands that are run for this project are shipped with the `graphviz` package.

** Mac **
```
brew install graphviz
```

** Ubuntu/Debian **
The dot package for graphviz should come pre-installed on most ships of Debian, however if it's not there:
```
sudo apt-get install graphviz
```

### Installing
Clone this repository and navigate to the c-networks directory where you'll make the bin directory for executables
```
git clone https://github.com/smit2300/data-structures.git
cd data-structures/graphs-networks/c-networks
mkdir bin
```

Build
```
make all
```

And that's it! You should now have two executables, one for building a graph through the use of an adjacency matrix and the other using an adjacency list.

## Examples

### Adjacency List
**20-node graph in random layout**
```
bin/list-network -d graphviz/20_node_list_graph.dot -n 20 -v
dot -Tpng graphviz/20_node_list_graph.dot -o 20_node_list_graph.png
```
IMAGE HERE

**15-node graph in circular layout**
```
bin/list-network -d graphviz/15_node_list_graph.dot -n 15 -v
circo -Tpng graphviz/15_node_list_graph.dot -o 15_node_list_graph.png
```
IMAGE HERE

### Adjacency Matrix
**20-node graph in circular layout**
```
bin/matrix-network -d graphviz/20_node_matrix_graph.dot -n 20 -v
circo -Tpng graphviz/20_node_matrix_graph.dot -o 20_node_matrix_graph.png
```
IMAGE HERE

**20-node graph in circular layout (higher connectivity)**
```
bin/matrix-network -d graphviz/20_node_matrix_graph_2.dot -n 20 -p -v
circo -Tpng graphviz/20_node_matrix_graph_2.dot -o 20_node_matrix_graph_2.png
```
IMAGE HERE
