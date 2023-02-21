-- filter span elements from header 3

function filter_span(inline)
  if inline.t == 'Span' then
    return pandoc.Span("")
  end
end

function Header(el)
    if el.level == 3 then
      return pandoc.walk_block(el, { Inline = filter_span })
    end
  end