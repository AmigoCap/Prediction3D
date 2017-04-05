//
//  ImageResize.swift
//  ImageProc
//
//  Created by Arthur Maia Mendes on 26/03/2017.
//  Copyright © 2017 Arthur Maia Mendes. All rights reserved.
//

import UIKit

class ImageResize {
    let maxDimension: Int
    init (maxDimension: Int) {
        self.maxDimension = maxDimension
    }
    
    func isSmallEnough(w: Int, h: Int) -> Bool {
        return w < maxDimension && h < maxDimension
    }
    
    func resizeImage(original: UIImage) -> UIImage {
        var w = Int(original.size.width)
        var h = Int(original.size.height)
        
        if isSmallEnough(w: w, h: h) {
            return original // Already small enough
        }
        
        while (!isSmallEnough(w: w, h: h)) {
            print("width \(w) height \(h)")
            w = Int(Double(w)*0.75)
            h = Int(Double(h)*0.75)
            print("width \(w) height \(h)")
        }
        
        return scaleToNewSize(image: original, w: w, h: h)
    }
    
    private func scaleToNewSize(image: UIImage, w: Int, h: Int) -> UIImage {
        let CGImage = image.cgImage
        let bitsPerComponent = CGImage!.bitsPerComponent
        let bytesPerRow = CGImage!.bytesPerRow
        let colorSpace = CGImage!.colorSpace
        let bitmapInfo = CGImage!.bitmapInfo
        let context = CGContext(data: nil, width: w, height: h, bitsPerComponent: bitsPerComponent, bytesPerRow: bytesPerRow, space: colorSpace!, bitmapInfo: bitmapInfo.rawValue)
        
        let CGPointZero = CGPoint(x: 0, y: 0)
        
        context!.interpolationQuality = CGInterpolationQuality.high
        
        context?.draw(CGImage!, in: CGRect(origin: CGPointZero, size: CGSize(width: CGFloat(w), height: CGFloat(h))))
        
        let scaledCGImage = context!.makeImage()!
        
        return UIImage(cgImage: scaledCGImage)
    }
}
