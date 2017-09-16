#ifndef GDWG
#define GDWG

#include <map>
#include <set>
#include <memory>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <iterator>

namespace gdwg {
	template <typename N, typename E>
	class Graph {
		private:
			struct Node;

			struct compareNode {
				bool operator()(const std::weak_ptr<Node> &a, const std::weak_ptr<Node> &b) const;
			};

			struct Node {
				N data_;
				mutable std::map<std::weak_ptr<Node>, std::set<E>, compareNode> neighbours_;

				Node(const N &data) : data_{data} {}
			};

			unsigned int cleanAndGetDegree(const Node &n) const;

			std::map<N, std::shared_ptr<Node>> nodes_;
			
		public:
			Graph() = default;
			Graph(Graph<N,E> &&) = default;
			Graph<N,E> &operator=(Graph<N,E> &&) = default;

			Graph(const Graph<N,E> &);
			Graph<N,E> &operator=(const Graph<N,E> &);

			bool addNode(const N &val);
			bool addEdge(const N &src, const N &dst, const E &w);

			bool replace(const N& oldData, const N& newData);
			void mergeReplace(const N& oldData, const N& newData); 

			void deleteNode(const N&) noexcept;
			void deleteEdge(const N& src, const N& dst, const E& w) noexcept;
			void clear() noexcept;

			bool isNode(const N &val) const;
			bool isConnected(const N& src, const N& dst) const;

			void printNodes() const;
			void printEdges(const N& val) const;
	};

	#include "Graph.tem"
}

#endif
