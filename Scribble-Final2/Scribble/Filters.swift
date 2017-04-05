//
//  Filters.swift
//  ImageProc
//
//  Created by Arthur Maia Mendes on 26/03/2017.
//  Copyright © 2017 Arthur Maia Mendes. All rights reserved.
//

import Foundation

class ScaleIntensityFilter : Filter {
    let scale: Double
    init(scale: Double) {
        self.scale = scale
    }
    
    func apply(input: Image) -> Image {
        return input.transformPixels(transformFunc: {
            (p1: RGBAPixel)-> RGBAPixel in
            var p = p1
            p.red = UInt8(Double(p.red) * self.scale)
            p.green = UInt8(Double(p.green) * self.scale)
            p.blue = UInt8(Double(p.blue) * self.scale)
            return p
        })
    }
    
}

class MixFilter : Filter {
    func apply(input: Image) -> Image {
        return input.transformPixels(transformFunc: {
            (p1: RGBAPixel)-> RGBAPixel in
            var p = p1
            
            let r = p.red
            p.red = p.blue
            p.blue = p.green
            p.green = r
            return p
        })
    }
    
}

class GreyScaleFilter : Filter {
    func apply(input: Image) -> Image {
        return input.transformPixels(transformFunc: {
            (p: RGBAPixel)-> RGBAPixel in
            let i = p.averageIntensity
            return RGBAPixel(r:i, g:i, b:i)
        })
    }
    
}

class BinaryFilter : Filter {
    func apply(input: Image) -> Image {
        return input.transformPixels(transformFunc: {
            (p: RGBAPixel)-> RGBAPixel in
            let i = p.averageIntensity
            let b:UInt8
            if i < 128 {
                b = 0
            } else {
                b = 255
            }
            return RGBAPixel(r:b, g:b, b:b)
        })
    }
    
}
