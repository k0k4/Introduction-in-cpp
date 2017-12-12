
template<class T, class P> class Pair
{
private:
	T tval;
	P pval;

public:

	Pair(T t, P p)
		:tval(t), pval(p) {}

	T getT() { return tval; }
	P getP() { return pval; }

};

