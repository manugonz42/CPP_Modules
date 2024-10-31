BitcoinExchange::BitcoinExchange() : type("NONE") {
};
BitcoinExchange::BitcoinExchange(BitcoinExchange& other) : type(other.base()){
}
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange& other){
	if (this != &other){
		this->base = other.base();
	}
	return *this;
}
BitcoinExchange::~BitcoinExchange(){
}