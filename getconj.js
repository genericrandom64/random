var page = require('webpage').create();
var system = require('system');
page.open('https://conjugator.reverso.net/conjugation-french-verb-' + system.args[1] + '.html', function () {
	setTimeout(function() {
		console.log(page.content);
phantom.exit();
	}, 5000);
});
