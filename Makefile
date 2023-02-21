# Convert to Markdown from the org-mode source files
#
# In order to use this makefile, you need some tools:
# - GNU make
# - Pandoc

# All org-mode files inside subfolders are considered sources
sources := $(shell find -name '*.org')

# Convert the list of source files (org-mode files inside subdirectories)
# into a list of output files (Markdown files in same directory as source).
objects := $(patsubst %.org,%.md,$(sources))

all: $(objects)

# Recipe for converting a org-mode file into Markdown using Pandoc
%.md: %.org
	pandoc \
		--include-in-header=header.yaml \
		--lua-filter=fix_img_org2md.lua \
		--lua-filter=fix_add_author_title.lua \
		--lua-filter=fix_includes.lua \
		--lua-filter=fix_remove_header_tags.lua \
		--markdown-headings=atx \
		--wrap=none \
		--highlight=kate \
		-f org $< \
		-t markdown_strict+backtick_code_blocks+pipe_tables+tex_math_dollars+raw_html+fancy_lists \
		-o $@

.PHONY : clean

# Clean markdown files inside subdirectories only
clean:
	find ./*/ -name \*.md -type f -delete
