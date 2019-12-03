#pragma once

#include "OpenGL/OpenGL.h"
#include "Utility/Colour.h"
#include <SFML/Graphics/RenderTarget.hpp>

class Palette;

class GLCanvas : public wxGLCanvas, sf::RenderTarget
{
public:
	GLCanvas(wxWindow* parent, int id = wxID_ANY);
	virtual ~GLCanvas() {}

	bool activateContext();
	void setup2D();
	void clear(ColRGBA colour = ColRGBA::BLACK);
	void reset();
	void refresh() { render(); }
	void drawCheckeredBackground() const;

	void beginSFMLDraw();
	void endSFMLDraw();

	// sf::RenderTarget
	sf::Vector2u getSize() const override;

protected:
	bool sfml_draw_ = false;

	virtual void drawContent();

private:
	void render();

	// sf::RenderTarget
	bool setActive(bool active) override;
};