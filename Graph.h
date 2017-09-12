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

			class compareNode {
				public:
					bool operator()(const std::weak_ptr<Node> &a, const std::weak_ptr<Node> &b);
			};

			struct Node {
				N data_;
				std::map<E, std::set<std::weak_ptr<Node>, compareNode>> neighbours_;
				unsigned int degree_;

				Node(const N &data) : data_{data} {}
			};

			std::map<N, std::shared_ptr<Node>> nodes_;
			
		public:
			Graph() = default;

			bool addNode(const N &val);
			bool isNode(const N &val) const;
			bool addEdge(const N &src, const N &dst, const E &w);

			void printNodes() const;
			void printEdges(const N& val) const;
	};

	#include "Graph.tem"
}

#endif
