

default: 
	pdflatex resstmt
	bibtex resstmt
	pdflatex resstmt
	pdflatex resstmt
	
	pdflatex tchstmt


clean:
	rm -f *~
	rm -f text/*~ bib/*~
	rm -f resstmt.log resstmt.bbl resstmt.blg resstmt.aux resstmt.out resstmt.fls resstmt.fdb_latexmk
	rm -f resstmt.pdf
	rm -f tchstmt.log tchstmt.blg tchstmt.aux tchstmt.out tchstmt.fls tchstmt.fdb_latexmk
	rm -f tchstmt.pdf

