prologues:=3;
verbatimtex
%&latex
\documentclass{minimal}
\begin{document}
etex
u := 1cm;
color col[];
col1 = (27 / 255, 158 / 255, 119 / 255);
col2 = (217 / 255, 95 / 255, 2 / 255);
col3 = (117 / 255, 112 / 255, 179 / 255);
col4 = (231 / 255, 41 / 255, 138 / 255);
col5 = (102 / 255, 166 / 255, 30 / 255);
col6 = (230 / 255, 171 / 255, 2 / 255);

beginfig(0);
	pair a;
	a := (0, 0);
	pair b;
	b := (2u, 0);
	pair c;
	c := (4u, 0);
	drawarrow a -- b;
	drawarrow b{1, 1} .. c{1, -1};
	drawarrow c{-1, -1} .. b{-1, 1};
	dotlabel.lft("6", a);
	dotlabel.ulft("3", b);
	dotlabel.urt("1", c);
	label.top("1", point 0.5 of (b{1, 1} .. c{1, -1}));
	label.top("2", point 0.5 of (a -- b));
	label.bot("3", point 0.5 of (c{-1, -1} .. b{-1, 1}));
endfig;

end