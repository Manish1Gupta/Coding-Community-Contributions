let weather={
	"apiKey":"063031b5e96f425e9489d28b04ebb725",
	fetchWeather: function(city){
		fetch(
			"https://api.openweathermap.org/data/2.5/weather?q="
			+city
			+"&units=metric&appid="
			+this.apiKey
		).then((resp) => resp.json())
		.then((data) => this.displayWeather(data))
	},
	displayWeather: function(data){
		const {name} = data;
		const {icon,description} = data.weather[0];
		const {temp,humidity} = data.main;
		const {speed} = data.wind;

		document.querySelector('.city').innerText="Weather in "+name;
		document.querySelector('.temp').innerText=temp+"°C";
		document.querySelector('.desc').innerText=description;
		document.querySelector('.humidity').innerText="Humidity: "+humidity;
		document.querySelector('.wind').innerText="Wind Speed: "+speed+"Km/h";
		document.querySelector('.icon').src="https://openweathermap.org/img/wn/"+icon+".png";

		document.body.style.backgroundImage = "url('https://source.unsplash.com/1600x900/?"+description+"')";
	},
	search:function(){
		this.fetchWeather(document.querySelector('.search-bar').value);
	}
};

document.querySelector('.search button').addEventListener('click',function(){
	weather.search();
});

document.querySelector('.search-bar').addEventListener('keyup',function(e){
	if (e.key=='Enter'){
		weather.search();
	}
})

window.addEventListener('load',function(){
	weather.fetchWeather('chennai');
})