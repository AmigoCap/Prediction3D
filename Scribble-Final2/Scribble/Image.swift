//
//  Image.swift
//  Scribble
//
//  Created by Arthur Maia Mendes on 25/03/2017.
//  Copyright © 2017 Caroline Begbie. All rights reserved.
//

import UIKit

public class Image {
    
    let pixels: UnsafeMutableBufferPointer<RGBAPixel>
    let height: Int
    let width: Int
    
    let bitsPerComponent = Int(8)
    let bytesPerRow: Int
    let colorSpace = CGColorSpaceCreateDeviceRGB()
    let bitmapInfo: UInt32 = CGBitmapInfo.byteOrder32Big.rawValue | CGImageAlphaInfo.premultipliedLast.rawValue
    
    
    public init(width: Int, height: Int) {
        self.height = height
        self.width = width
        
        bytesPerRow = 4 * width
        
        let rawData = UnsafeMutablePointer<RGBAPixel>.allocate(capacity: (width * height))
        
        pixels = UnsafeMutableBufferPointer<RGBAPixel>(start: rawData, count: width * height)
    }
    
    public init(image: UIImage) {
        height = Int(image.size.height)
        width = Int(image.size.width)
        
        bytesPerRow = 4 * width
        
        let rawData = UnsafeMutablePointer<RGBAPixel>.allocate(capacity: (width * height))
        
        let CGPointZero = CGPoint(x: 0, y: 0)
        let rect = CGRect(origin: CGPointZero, size: image.size)
        
        let imageContext = CGContext(data: rawData, width: width, height: height, bitsPerComponent: bitsPerComponent, bytesPerRow: bytesPerRow, space: colorSpace, bitmapInfo: bitmapInfo)
        
        imageContext?.draw(image.cgImage!, in: rect)
        
        pixels = UnsafeMutableBufferPointer<RGBAPixel>(start: rawData, count: width * height)
    }
    
    public func getPixel(x: Int, y:Int) -> RGBAPixel{
        return pixels[x+y*width]
    }
    
    public func setPixel(value: RGBAPixel, x: Int, y:Int){
        pixels[x+y*width] = value
    }
    
    public func toUIImage() -> UIImage {
        let outContext = CGContext(data: pixels.baseAddress, width: width, height: height, bitsPerComponent: bitsPerComponent,bytesPerRow: bytesPerRow,space: colorSpace,bitmapInfo: bitmapInfo,releaseCallback: nil,releaseInfo: nil)
        
        return UIImage(cgImage: outContext!.makeImage()!)
    }
    
    public func transformPixels( transformFunc: (RGBAPixel) -> RGBAPixel) -> Image {
        let newImage = Image(width: self.width, height: self.height)
        for y in 0..<height {
            for x in 0..<width {
                let p1 = getPixel(x: x,y: y)
                let p2 = transformFunc(p1)
                newImage.setPixel(value: p2, x: x, y: y)
            }
        }
        return newImage
    }
    
    public func getMatrix() -> [UInt8] {
        var mat = [UInt8]()
        for y in 0..<height {
            for x in 0..<width {
                let p1 = getPixel(x: x,y: y)
                mat.append(p1.red)
            }
        }
        return mat
    }
}
