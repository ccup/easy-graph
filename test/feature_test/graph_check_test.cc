#include <cctest/cctest.h>
#include "easy_graph/builder/graph_dsl.h"
#include "easy_graph/checker/graph_checker.h"
#include "easy_graph/checker/node_checker.h"
#include "easy_graph/checker/edge_checker.h"
#include "easy_graph/edges/default_edge_type_register.h"
#include "easy_graph/matcher/matcher.h"
#include "easy_graph/pred/concrete/node_equal.h"
#include "easy_graph/pred/concrete/linked_from.h"

USING_EG_NS

REG_DEFAULT_EDGE_TYPE(data_edge());

FIXTURE(GraphCheckTest) {

	GRAPH(g1, "subgraph") {
		CHAIN(Node("a") -> Node("b", attr_of("sink", true)));
	};

	GRAPH(sample) {
		auto subgraph = subgraph_of(g1, "se", iw_of(1, ep_of("a", 1)));

		CHAIN(Node("a") -> Node("b") -> Node("c") -> Node("d") -> Node("e", subgraph));
		CHAIN(Node("a") -> Data(1, 1) -> Node("b") -> Edge(ctrl_edge(), attr_of("label", "to")) -> Node("e"));
	};

	TEST("should assert graph info") {

		CHECK_GRAPH(sample) {
			ASSERT_EQ("sample", graph.name);
			ASSERT_EQ(5       , graph.nodeCount);
			ASSERT_EQ(6       , graph.edgeCount);
		};

		CHECK_GRAPH(sample) {
			ASSERT_TRUE(graph.hasNode("a"));
			ASSERT_TRUE(graph.hasNode("b"));
			ASSERT_TRUE(graph.hasNode("c"));
			ASSERT_TRUE(graph.hasNode("d"));
			ASSERT_TRUE(graph.hasNode("e"));
		};

		CHECK_GRAPH(sample) {
			ASSERT_TRUE(graph.hasEdge(edge_of("a", "b")));
			ASSERT_TRUE(graph.hasEdge(edge_of("b", "c")));
			ASSERT_TRUE(graph.hasEdge(edge_of("c", "d")));
			ASSERT_TRUE(graph.hasEdge(edge_of("b", "e", ctrl_edge())));
			ASSERT_TRUE(graph.hasEdge(edge_of("d", "e", data_edge())));
		};

		CHECK_GRAPH(sample) {
			ASSERT_FALSE(graph.hasNode("f"));
			ASSERT_FALSE(graph.hasEdge(edge_of("a", "e")));
			ASSERT_FALSE(graph.hasEdge(edge_of("e", "f")));
			ASSERT_FALSE(graph.hasEdge(edge_of("c", "d", ctrl_edge())));
			ASSERT_FALSE(graph.hasEdge(edge_of(ep_of("a", 1), ep_of("b", 0))));
			ASSERT_FALSE(graph.hasEdge(edge_of(ep_of("a"), ep_of("b"), ctrl_edge())));
		};

		CHECK_GRAPH(sample) {
			GRAPH(g1) {
				CHAIN(Node("a") -> Node("b"));
			};

			GRAPH(expect) {
				CHAIN(Node("a") -> Node("b") -> Node("c") -> Node("d") -> Node("e", subgraph_of(g1, iw_of(1, ep_of("a", 1)))));
				CHAIN(Node("a") -> Data(1, 1) -> Node("b"));
				CHAIN(Node("b") -> Edge(ctrl_edge()) -> Node("e"));
			};

			ASSERT_GRAPH_EQ(expect);
		};
	}

	TEST("should assert node info") {

		CHECK_NODE(g1, "b") {
			ASSERT_EQ(1, node.inputCount);
			ASSERT_EQ(0, node.outputCount);
			ASSERT_EQ(0, node.subgraphCount);
			ASSERT_TRUE(node.getAttr<bool>("sink"));
			ASSERT_TRUE(*node.getAttr<bool>("sink"));
			ASSERT_FALSE(node.getAttr<bool>("source"));
		};

		CHECK_NODE(sample, "a") {
			ASSERT_EQ(0, node.inputCount);
			ASSERT_EQ(2, node.outputCount);
		};

		CHECK_NODE(sample, "a") {
			ASSERT_TRUE(node.isSource());
			ASSERT_TRUE(node.prevNextTo("b"));
		};

		CHECK_NODE(sample, "a") {
			ASSERT_FALSE(node.isSink());
			ASSERT_FALSE(node.isIsolated());
			ASSERT_FALSE(node.prevNextTo("d"));
		};

		CHECK_NODE(sample, "b") {
			ASSERT_TRUE(node.prevNextTo("c"));
			ASSERT_TRUE(node.postNextTo("a"));
		};

		CHECK_NODE(sample, "e") {
			ASSERT_EQ(1, node.subgraphCount);
			ASSERT_TRUE(node.isSink());
			ASSERT_TRUE(node.postNextTo("d"));
			ASSERT_TRUE(node.hasSubgraph("se"));
			ASSERT_FALSE(node.hasSubgraph("subgraph"));
		};
	}

	TEST("should assert edge info") {
		CHECK_EDGE(sample, edge_of("b", "e", ctrl_edge())) {
			ASSERT_TRUE(edge.getAttr<const char*>("label"));
			ASSERT_EQ("to", *edge.getAttr<const char*>("label"));
			ASSERT_FALSE(edge.getAttr<const char*>("cond"));
		};
	}

	TEST("should match patterns") {
		CHECK_GRAPH(sample) {
			auto node_a = NodeEqual(node_of("a"));
			auto link_c = LinkedFrom("c");
			ASSERT_TRUE(graph.match(Matcher().pred(&node_a).pred(&link_c)));
		};
	}
};
