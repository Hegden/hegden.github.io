

default: 
	pdflatex syllabus
	bibtex syllabus
	pdflatex syllabus
	pdflatex syllabus

clean:
	rm -f *~
	rm -f text/*~ bib/*~
	rm -f syllabus.log syllabus.bbl syllabus.blg syllabus.aux syllabus.out syllabus.fls syllabus.fdb_latexmk
	rm -f syllabus.pdf

