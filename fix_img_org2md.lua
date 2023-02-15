-- translate org-mode image notation to markdown
function Link(el)
    if el.title == '' and el.target:match('.*[.][png|jpg|jpeg|PNG|JPG|JPEG|SVG|svg]') then
    return pandoc.Image('', el.target:gsub('file:', ''), '')
    end
  end