#include "easy_graph/graph/subgraph.h"
#include "easy_graph/graph/graph.h"
#include "easy_graph/graph/wire_visitor.h"
#include "easy_graph/infra/container_eq.h"

EG_NS_BEGIN

Subgraph::Subgraph(const Graph& graph)
: name(graph.getName()), graph(graph){
}

__DEF_EQUALS(Subgraph) {
	return (this->graph == rhs.graph) &&
			container_is_equal(inputWires, rhs.inputWires) &&
			container_is_equal(outputWires, rhs.outputWires);
}

void Subgraph::setName(const std::string& name) {
	this->name = name;
}

std::string Subgraph::getName() const {
	return name;
}

const Graph& Subgraph::getGraph() const {
	return graph;
}

void Subgraph::wireUp(const InputWire& wire) {
	inputWires.push_back(wire);
}

void Subgraph::wireUp(const OutputWire& wire) {
	outputWires.push_back(wire);
}

void Subgraph::accept(WireVisitor& visitor) const {
	std::for_each(inputWires.cbegin(), inputWires.cend(),  [&visitor](const auto& wire) {
		visitor.visit(static_cast<InputWire>(wire));
	});
	std::for_each(outputWires.cbegin(), outputWires.cend(),  [&visitor](const auto& wire) {
		visitor.visit(static_cast<OutputWire>(wire));
	});
}

EG_NS_END
