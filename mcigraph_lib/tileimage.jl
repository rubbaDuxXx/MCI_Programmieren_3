using Images
tilepath = "/home/paethon/Dropbox/18_18_ss/programmieren_3/mcigraph_lib/tiles"

tilenames = readdir(tilepath)
tilenames .= joinpath.(tilepath, tilenames)

function generatetilearray(tilenames, xsize, ysize)
    randtile() = load(tilenames[rand(1:length(tilenames))])
    function getline()
        line = randtile()
        for x in 1:xsize-1
            line = [line randtile()]
        end
        return line
    end
    res = getline()
    for y in 1:ysize-1
        res = [res ; getline()]
    end
    return res
end

t = generatetilearray(tilenames, 32, 8)
save("/home/paethon/Dropbox/18_18_ss/programmieren_3/mcigraph_lib/tiles.png", t)
