

default: 
	pdflatex notes
	bibtex notes
	pdflatex notes
	pdflatex notes

clean:
	rm -f *~
	rm -f text/*~ bib/*~
	rm -f notes.log notes.bbl notes.blg notes.aux notes.out notes.fls notes.fdb_latexmk
	rm -f notes.pdf

