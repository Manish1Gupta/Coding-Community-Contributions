let outerdiv = document.querySelector('.outer')
const arrfunc=(arr)=>{
    outerdiv.innerHTML=''
    arr.forEach(l => {
        let div = document.createElement('div')
        let span = document.createElement('span')
        span.textContent=l
        div.style.width='200px'
        div.style.height='160px'
div.className='ws' 
div.appendChild(span)
      
        outerdiv.append(div)
    });

}
const newcount = countries.map(l=>{
    return l.toUpperCase()
})
arrfunc(newcount)

let startwordbutton= document.querySelector('.startlet')
let anyletterbutton = document.querySelector('.anylet')
let input = document.querySelector('.searchinput')

let reset= document.querySelector('#anylet')

startwordbutton.addEventListener('click',()=>{
    if(anyletterbutton.classList.contains('dark')){
        anyletterbutton.classList.remove('dark')
    }
    startwordbutton.classList.toggle('dark')
 })

anyletterbutton.addEventListener('click',()=>{
    if(startwordbutton.classList.contains('dark')){
        startwordbutton.classList.remove('dark')
    }
    anyletterbutton.classList.toggle('dark')
})



reset.addEventListener('click',()=>{
    if(startwordbutton.classList.contains('dark')){
        startwordbutton.classList.remove('dark')
    }
    if(anyletterbutton.classList.contains('dark')){
        anyletterbutton.classList.remove('dark')
    }
    input.value=''
    arrfunc(newcount)
})


input.addEventListener('input',()=>{
    // outerdiv.innerHTML=''
    let n  = input.value
    if(startwordbutton.classList.contains('dark')){
        let startletcounries = newcount.filter(e=>{
           return e.startsWith(n.toUpperCase())
        })
        console.log(startletcounries)
        arrfunc(startletcounries)
    }
    else if(anyletterbutton.classList.contains('dark')){
        let anyletcountry = newcount.filter(l=>{
            return l.includes(n.toUpperCase())
        })
    arrfunc(anyletcountry)
    console.log(anyletcountry)
    }
    else{
        arrfunc(countries)
    }
})

