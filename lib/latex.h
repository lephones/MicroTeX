#ifndef LATEX_LATEX_H
#define LATEX_LATEX_H

#include <string>

#include "config.h"
#include "unimath/uni_font.h"
#include "render.h"

namespace tex {

class CLATEXMATH_EXPORT LaTeX {
private:
  static volatile bool _isInited;
  static std::string _defaultMathFontName;

#if GLYPH_RENDER_TYPE == 0
  static bool _renderGlyphUsePath;
#endif

public:
  /**
   * Initialize LaTeX context with given math font spec, at least we need
   * a math font to layout formulas.
   *
   * @param mathFontSpec the font spec to load math font
   */
  static void init(const FontSpec& mathFontSpec);

  /**
   * Initialize LaTeX context with given math font spec, using byte buffer,
   * at least we need a math font to layout formulas.
   *
   * @param name the name of the math font spec
   * @param len buffer length
   * @param data the byte buffer
   */
  static void init(
    const std::string& name,
    size_t len, const u8* data
  );

  /** Check if context is initialized */
  static bool isInited();

  /**
   * Add main font (collection) to context.
   *
   * @param name the name of the font (collection)
   * @param params font spec to load
   */
  static void addMainFont(const std::string& name, const std::vector<FontSpec>& params);

  /**
   * Add math font to context.
   *
   * @param params font spec to load
   */
  static void addMathFont(const FontSpec& params);

  /**
   * Set the default math font to show formulas while math font
   * was not given.
   *
   * @param name the math font name, must exists or an `ex_invalid_param`
   *   will be thrown.
   */
  static void setDefaultMathFont(const std::string& name);

  /**
   * Override the style to display formulas. If #enable is true, the '$', '$$',
   * '\(' and '\[' will be ignored, and force to use the given overridden style.
   *
   * @param enable whether enable the overridden style, false to cancel
   * @param style the target style to override
   */
  static void overrideTexStyle(bool enable, TexStyle style = TexStyle::text);

#if GLYPH_RENDER_TYPE == 0

  /** Set if use path to render glyphs */
  static void setRenderGlyphUsePath(bool use);

  /** Test if currently use path to render glyphs */
  static bool isRenderGlyphUsePath();

#endif

  /**
   * Parse LaTeX string to Render
   *
   * @param tex the TeX formatted string
   * @param width the width of the 2D graphics context
   * @param textSize the text size
   * @param lineSpace the line space
   * @param fg the foreground color
   * @param mathFontName the math font name
   * @param mainFontName the main font name
   */
  static Render* parse(
    const std::string& tex,
    int width,
    float textSize,
    float lineSpace,
    color fg,
    const std::string& mathFontName = "",
    const std::string& mainFontName = ""
  );

  /** Release the LaTeX context */
  static void release();
};

}  // namespace tex

#endif  // LATEX_LATEX_H
