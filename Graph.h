#ifndef GDWG
#define GDWG

#include <map>
#include <memory>

namespace gdwg {
	template <typename N, typename E>
	class Graph {
		private:
			struct Node {
				N data_;
				std::map<E, std::map<N, std::shared_ptr<Node>>> nodes_;
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
