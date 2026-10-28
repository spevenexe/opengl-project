#include "VertexArray.h"
#include "Renderer.h"

VertexArray::VertexArray() {
	GLCall(glGenVertexArrays(1, &m_rendererID));
}
VertexArray::~VertexArray() {
	GLCall(glDeleteVertexArrays(1, &m_rendererID));
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) {
	Bind();
	vb.Bind();
	const auto& elements = layout.GetElements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& _element = elements[i];
		GLCall(glVertexAttribPointer(i, _element.count, _element.type, _element.normalized, layout.GetStride(), (const void*)offset)); // how should GPU interpret the data?
		GLCall(glEnableVertexAttribArray(i)); // you have to enable the attribute, based on its 

		offset += _element.count * VertexBufferElement::GetSizeOfType(_element.type);
	}
}
void VertexArray::Bind() const {
	GLCall(glBindVertexArray(m_rendererID));
}

void VertexArray::UnBind() const {
	GLCall(glBindVertexArray(0));
}