# About this repo
Code for _The C Programming Language 2nd Ed._ (K&R2) Kernighan & Ritchie, 1988, Prentice Hall

Build instructions are embedded in source files or sub-directories.

This repo contains exercises, original solutions, code snippets, examples, thoughts, etc. related to K&R2. The excerpts are left as close as posssible to the text while still building on a real modern system.

Most code uses Standard C 89 like the text, Standard C Library (default GCC and GNU Lib C on Ubuntu 20.04), with no other dependencies. Some code might use GNU C extensions and should be noted.

This code isn't designed to be completely correct in all cases, only meant to fulfill the spirit of the exercise. With few exceptions, safety and portability are not a consideration. That is, these code snippets are mainly for pedagogical purposes, not for production or expert reference.

The plan is to eventually add more helpful comments and test code.

Rebuild the Vim spelling file in Vim with: :mkspell kr2.utf-8.add

### Contents
- ch1-ch8 directories: mostly solutions, split into chapters.
- template.[ch]:       convenient starting point for source files.
- README.md:           this Markdown file.
- LICENSE:             specify license for files in this repo.
- kr2.utf-8.add:       project-level vim dictionary files for spell checking.
- INSTALL:             how to use the files in this repo.
- TODO:                ideas and next planned next steps.
