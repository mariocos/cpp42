#include "harl.hpp"

int main(void)
{
	harl	bot;

	bot.complain("debug");
	bot.complain("info");
	bot.complain("warning");
	bot.complain("error");
	bot.complain("");
	bot.complain("i hate complaining");
}