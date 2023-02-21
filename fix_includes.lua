local system = require 'pandoc.system'
local path = require 'pandoc.path'

local function file_exists(name)
  local f = io.open(name, 'r')
  if f ~= nil then
    io.close(f)
    return true
  else
    return false
  end
end

local function read_file(name)
  local f = io.open(name, 'r')
  if f ~= nil then
    local content = f:read('*all')
    io.close(f)
    return content
  else
    return nil
  end
end

function RawBlock(el)
  _, _, srcfile, srctype = string.find(el.text, '#[+]INCLUDE: ["](.+)["] %a+ (.+)')

  --print(el.text)
  if srcfile == nil then
    return el
  end

  basedir = path.directory(PANDOC_STATE.input_files[1])
  
  --print(basedir)
  --print(srcfile)
  --print(srctype)
  --print(system.get_working_directory())
  
  fullfile = path.join({basedir, srcfile})
  if file_exists(fullfile) then
    src = read_file(fullfile)
    --print(fullfile)
    return pandoc.CodeBlock(src, {class = srctype})
  end

  --local filetype = extension_for[FORMAT] or 'svg'
  --local fbasename = pandoc.sha1(el.text) .. '.' .. filetype
  --local fname = system.get_working_directory() .. '/' .. fbasename
  --if not file_exists(fname) then
  --  tikz2image(el.text, filetype, fname)
  --end
  --return pandoc.Para({pandoc.Image({}, fbasename)})
end