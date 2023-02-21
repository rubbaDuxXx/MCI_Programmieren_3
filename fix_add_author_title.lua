local List = require 'pandoc.List'

-- helper function to check for empty string
local function isempty(s)
  return s == nil or s == ''
end

-- get title authors from metadata and insert as first slide
function Pandoc(doc)
    local meta = doc.meta
    local body = List:new{}

    -- get authors as comma separated string from metadata
    authorsStr = ""
    if not isempty(meta.author) then
      authorsStr = pandoc.utils.stringify(meta.author)
    end
    
    titleStr = ''
    if not isempty(meta.title) then
      titleStr = pandoc.utils.stringify(meta.title)
    end

    -- insert title and author slide first
    if not isempty(titleStr) then
      body:extend(List:new{pandoc.Header(1, titleStr)})
      body:extend(List:new{pandoc.RawBlock('html', '<!--\n_paginate: false\n_class: title lead\n-->')})
      if not isempty(authorsStr) then
        body:extend(List:new{pandoc.Para(authorsStr)})
      end
    end
    
    -- add rest of document
    body:extend(doc.blocks)

    -- strip metadata
    return pandoc.Pandoc(body, nil)
  end

-- debug function to print pandoc tables
local function tprint (tbl, indent)
  if not indent then indent = 0 end
  local toprint = string.rep(" ", indent) .. "{\r\n"
  indent = indent + 2 
  for k, v in pairs(tbl) do
    toprint = toprint .. string.rep(" ", indent)
    if (type(k) == "number") then
      toprint = toprint .. "[" .. k .. "] = "
    elseif (type(k) == "string") then
      toprint = toprint  .. k ..  "= "   
    end
    if (type(v) == "number") then
      toprint = toprint .. v .. ",\r\n"
    elseif (type(v) == "string") then
      toprint = toprint .. "\"" .. v .. "\",\r\n"
    elseif (type(v) == "table") then
      toprint = toprint .. tprint(v, indent + 2) .. ",\r\n"
    else
      toprint = toprint .. "\"" .. tostring(v) .. "\",\r\n"
    end
  end
  toprint = toprint .. string.rep(" ", indent-2) .. "}"
  return toprint
end